/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkVkComplexToComplexFFTImageFilter_hxx
#define itkVkComplexToComplexFFTImageFilter_hxx

#include "itkVkComplexToComplexFFTImageFilter.h"

#include "itkImageRegionIterator.h"
#include "itkImageRegionConstIterator.h"

namespace itk
{

template <typename TImage>
VkComplexToComplexFFTImageFilter<TImage>
::VkComplexToComplexFFTImageFilter()
{}


template <typename TImage>
void
VkComplexToComplexFFTImageFilter<TImage>
::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);
}


template <typename TImage>
void
VkComplexToComplexFFTImageFilter<TImage>
::DynamicThreadedGenerateData(const OutputRegionType & outputRegion)
{
  OutputImageType *      output = this->GetOutput();
  const InputImageType * input = this->GetInput();
  InputRegionType inputRegion = InputRegionType(outputRegion.GetSize());

  itk::ImageRegionConstIterator<InputImageType> in(input, inputRegion);
  itk::ImageRegionIterator<OutputImageType>     out(output, outputRegion);

  for (in.GoToBegin(), out.GoToBegin(); !in.IsAtEnd() && !out.IsAtEnd(); ++in, ++out)
  {
    out.Set(in.Get());
  }
}

} // end namespace itk

#endif // itkVkComplexToComplexFFTImageFilter_hxx
